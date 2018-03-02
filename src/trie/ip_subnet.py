#!/usr/bin/env python

import logging
import socket
import sys


class InvalidValue(Exception):
    pass


class InvalidIP(InvalidValue):
    pass


class IPUtils(object):

    @classmethod
    def is_valid_ip(cls, addr):
        try:
            assert (addr.count('.') == 3)
            socket.inet_aton(addr)
            return True
        except Exception as err:
            return False

    @classmethod
    def get_binary(cls, num, pad = 0):
        '''
        Returns binary representation of the number.

        Parameters
        ----------------
        num : int
            Number to be converted to binary
        pad : int
            If not zero then represents minimum length of binary equivalent.
        '''
        try:
            binary, num = '', int(num)
            while(num):
                binary = str(num % 2) + binary
                num >>= 1
            binary = '0' if binary is None else binary
            if pad > len(binary):
                binary = '0' * (pad - len(binary)) + binary
        except Exception as err:
            raise InvalidValue("Error while getting binary for %s", num)
        return binary


class TrieNode(object):

    def __init__(self, val):
        self.val = val
        self.is_subnet = False

        # holds the children in left / right subtree
        self.zero = None    # left child
        self.one = None     # right child

    def mark_subnet(self, subnet=False):
        self.is_subnet = subnet if subnet else True

    def is_subnet(self):
        return self.is_subnet


class MatchIP(object):
    '''
    Gives the matching subnet(s) for the IP.
    '''

    def __init__(self, subnets):
        self.log = logging.getLogger(__name__)

        self.subnets = subnets if subnets is not None else []

        self.graph = TrieNode('root')
        self.build(subnets)

    def update(self, ip, mask):
        '''
        Updates trie based on IP and Mask.
        '''
        assert(self.graph)
        assert(mask <= 32 and mask >=0)

        node = self.graph
        for idx in range(mask):
            msb = ip[idx]
            assert (msb in ['0', '1'])
            child = node.zero if msb == '0' else node.one
            if not child:
                child = TrieNode(msb)
                if msb == '0':
                    node.zero = child
                else:
                    node.one = child
            node = child
            if mask == idx:
                child.mark_subnet(ip + str(mask))

    def add_subnet(self, subnet):
        try:
            subnet = subnet.split('/')
            assert(len(subnet) == 2)
            ip, mask = subnet[0], subnet[1]

            if not IPUtils.is_valid_ip(ip):
                raise InvalidIP("Bad IP Address")

            ip = ''.join([IPUtils.get_binary(x, pad=8) for x in ip.split('.')])
            self.update(ip, int(mask))

        except Exception as err:
            self.log.error("Cannot process subnet : %s", subnet)

    def build(self, subnets = None):
        """
        Expands the local Trie graph based on the subnests.
        """
        subnets = [] if subnets is None else subnets

        for subnet in subnets:
            self.add_subnet(subnet)

    def get_matching_subnets(self, ip):
        try:
            ip = ''.join([IPUtils.get_binary(x, pad=8) for x in ip.split('.')])
            node = self.graph

            ans = []
            for msb in ip:
                node = node.one if msb == '1' else node.zero
                if node.is_subnet():
                    ans.append(node.is_subnet())
            return ans
        except Exception as err:
            pass


if __name__ == '__main__':
    subnets = ['192.168.10.0/24', '192.168.20.0/24']
    print MatchIP(subnets=subnets).get_matching_subnets(ip='192.168.10.35')
