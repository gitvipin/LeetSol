#include <iostream>
#include <vector>
#include <list>

using namespace std;
// a2x2s31a12
// axsa223112

size_t swap(char data[], int start, int mid, int end){
    std::string str(data, mid, end - mid);
    std::string num(data, start, mid - start);

    for (std::string::iterator it = str.begin(); it != str.end(); it++)
        data[start++]=*it;

    size_t ret = start;

    for (std::string::iterator it = num.begin(); it != num.end(); it++)
        data[start++]=*it;
    return ret;
}

void arrange(char data[]){
    if (!*data)
        return ;

    size_t len, start, mid, end;
    len = strlen(data)-1;

    // move past the last integer
    for (;len > 0 ; len--)
        if (!(data[len] >= '0' and data[len] <= '9'))
            break;

    while (len > 0 ){
        end = len + 1;
        for (;len > 0 ; len--) {
            if (data[len] >= 'a' and data[len] <= 'z'){
                mid = len;
                continue;
            }
            break;
        }

        for (;len > 0 ; len--) {
            if (data[len] >= '0' and data[len] <= '9'){
                start = len;
                continue;
            }
            break;
        }
        if (start != mid){
            len = swap(data, start, mid , end) - 1 ;
            start = mid = end = len;
        } else {
            break;
        }
    }
}



int main (int argc , char *argv[]) {
    char * data = new char[strlen(argv[1])];
    strcpy(data, argv[1]);
    cout << "Hello world " << std::endl;
    std::cout << "Arrangement of " << data << " is" << std::endl;
    arrange(data);
    std::cout << data;
    return 0;
}
