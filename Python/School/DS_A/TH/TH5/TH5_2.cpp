// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <fstream>
// #include <conio.h>
using namespace std;
void pause(void) {
    system("echo '\nPress any key to continue...' && ( read x 2> nul; rm nul || pause > nul )");
    return;
}
void cls(void) {
    system("cls||clear");
    return;
}

struct SV {
    char MaSV[10], hoDem[30], ten[15];
    char sex[10];
    int year;
    float score;
};
struct Node {
    SV sv;
    Node* next;
};
typedef Node* ptr;
ptr L;

ptr CreateNode(SV sv) {
    ptr tmp = new Node;
    tmp->sv = sv;
    tmp->next = NULL;
    return tmp;
}
void Init(ptr& L) {
    L = NULL;
}
int empty(ptr L) {
    return L == NULL;
}
ptr DelHead(ptr& L) {
    L = L->next;
    return L;
}
