//
// Created by root on 18-3-7.
//

#ifndef DS_EXP_01_LINKLIST_H
#define DS_EXP_01_LINKLIST_H

#include <iostream>
#include <assert.h>

using namespace std;

template<typename D>
struct _LinkNode {
    _LinkNode *next;
    D data;
};

template<typename T>
class LinkList {
public:
    typedef struct _LinkNode<T> LinkNode;

    LinkList() : head(NULL), length(0) {
        head = new LinkNode;
        assert(head);
        head->next = NULL;
    }

    ~LinkList() {
        LinkNode *tempNode = NULL;
        LinkNode *p = head->next;
        while (p != NULL) {
            tempNode = p->next;
            delete p;
            p = tempNode;
        }
        delete (tempNode);
        tempNode = NULL;
        delete (head);
        p = NULL;
        length = 0;
    }

    void PrintNode() {
        LinkNode *temp = NULL;
        temp = head->next;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

public:
    int insertPost(T data) {
        LinkNode *pnode = new LinkNode;
        assert(pnode);
        pnode->data = data;
        pnode->next = NULL;

        LinkNode *p = NULL;
        p = head;

        while (p->next != NULL) {
            p = p->next;
        }
        p->next = pnode;
        length++;
        pnode = NULL;
        p = NULL;
        return 1;
    }

    int deleteNode(T data) {
        LinkNode *temp, *delnode;
        temp = head;
        while (temp->next != NULL && temp->next->data != data)
            temp = temp->next;
        if (temp->next == NULL) {
            cout << "not exist!" << endl;
            return 0;
        } else {
            delnode = temp->next;
            temp->next = delnode->next;
            delete delnode;
            length--;
            return 1;
        }
    }

    int insertPre(T data) {
        LinkNode *tmpNode = new LinkNode;
        tmpNode->data = data;
        tmpNode->next = head->next;
        head->next = tmpNode;
        length++;
        tmpNode = NULL;
        return 1;
    }

    void reverse() {
        LinkNode *preNode = NULL;
        LinkNode *curNode = NULL;
        LinkNode *nextNode = NULL;

        if (length == 1 || length == 0) {
            return;
        } else if (length >= 2) {
            preNode = head->next;
            curNode = preNode->next;
            nextNode = curNode->next;
            preNode->next = NULL;
            while (nextNode != NULL) {
                curNode->next = preNode;
                preNode = curNode;
                curNode = nextNode;
                nextNode = nextNode->next;
            }
            curNode->next = preNode;
            head->next = curNode;
        }
        preNode = NULL;
        curNode = NULL;
        nextNode = NULL;
    }

    size_t size() {
        return length;
    }

    LinkNode locateLink(T data);

    LinkNode locatePre(T data);


private:
    LinkNode *head;
    size_t length;
};

#endif //DS_EXP_01_LINKLIST_H
