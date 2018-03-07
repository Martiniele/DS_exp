#include "LinkList.h"

int main() {
    LinkList<double> list;
    list.insertPost(1.5);
    list.insertPost(2.5);
    list.insertPost(3.5);
    list.insertPost(2.25);
    list.insertPre(3.15);
    list.PrintNode();
    return 0;
}