#!/usr/bin/env python
'''
Converts the loaded JSON string into normalizd string output.
'''

# Examples: Left Hand Side (arbitrary object) -> Right Hand Side (string type)
#    1 -> 1
#    'foo' -> '"foo"'
#    [1, 'foo'] -> '[1,"foo"]'
#    [1] --> '[1] and NOT [1,]'
#    {'a': 1, 'b': 'asdf'} -> '{"a":1,"b":"asdf"}'
#    {'a': 1} -> '{"a":1}'
#    {'a': 1, 'b': 'asdf', 'c': [1, 'foo', {'d': 3}]} -> '{"a":1,"b":"asdf","c":[1,"foo", {"d": 3}]}'
#
# NB: All strings in JSON must be enclosed in double quotes.

# Useful type checking functions:
#  isinstance(obj, basestring)
#  isinstance(obj, int)
#  isinstance(obj, list)
#  isinstance(obj, dict)

import json
import sys


def normalize_output(json_str):
    try:
        output = json_encode(json_str)
        json_to_output = json.loads(output)
    except ValueError:
        return "JSON output not valid JSON!"

    return json.dumps(json_to_output, sort_keys=True)


def json_encode(obj):
    '''
    Returns the encoded JSON for the object 'obj'
    '''
    if obj is None:
        return 'null'
    elif isinstance(obj, basestring):
        return '"' + obj + '"'
    elif isinstance(obj, int):
        try:
            ret = str(obj)
        except Exception as err:
            print "cannot convert to string"
            raise
        return ret
    elif isinstance(obj, list):
        count, ret = len(obj), '['
        for i in range(count):
            ret += json_encode(obj[i])
            if i < count - 1:
                ret += ','
        ret += ']'
        return ret
    elif isinstance(obj, dict):
        i, count, ret = 0, len(obj.keys()), '{'
        for key, val in obj.iteritems():
            ret += json_encode(key) + ':'
            ret += json_encode(val)
            if i < count - 1:
                ret += ','
                i += 1
        ret += '}'
        # print ret
        return ret


if __name__ == '__main__':
    # parsed_json = json.load(sys.stdin)
    # print normalize_output(parsed_json)
    inputs = [(1, '1'),
              ('foo', '"foo"'),
              ([1, 'foo'], '[1, "foo"]'),
              ([1] , '[1]'),
              ({'a': 1, 'b': 'asdf'}, '{"a": 1, "b": "asdf"}'),
              ({'a': 1}, '{"a": 1}'),
              ({'a': 1, 'b': 'asdf', 'c': [1, 'foo', {'d': 3}]}, '{"a": 1, "b": "asdf", "c": [1, "foo", {"d": 3}]}')]

    for (x,y) in inputs:
        # import pdb ; pdb.set_trace()
        ans = normalize_output(x)
        print x , y, ans
        assert( ans == y)

