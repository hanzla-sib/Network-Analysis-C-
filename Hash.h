#pragma once
#include<iostream>
using namespace std;
#include"ADJlist.h"
class Hash
{
public:
    
    int BUCKET;    // No. of buckets
    int count = 0;
    // Pointer to an array containing buckets
    Adjlist* table;
    Hash() {
        BUCKET = 0;
        table = new Adjlist[BUCKET];
    }
    void setsize(int size) {
        BUCKET = size;
        table = new Adjlist[BUCKET];
        

    }

    
    void insertItem(int key) {
        int i = 0;
        bool check = false;
        int index = hashFunction(key);
     /*   if (i == 1) {
            table[index].cretelist(key);
            i++;
        }*/
      
       
        
             if (table[index].head != NULL) {
                 node* curr = table[index].head;
                 while (curr != NULL) {
                     if (curr->data == key) {
                         check = true;
                         break;
                     }
                     curr = curr->next;
                 }
                 if (check == false) {
                     table[index].cretelist(key);
                     count++;

                 }
           }
             else {
                 table[index].cretelist(key);
             }
            
        }
       
    

    void pus(int key) {
        int index = hashFunction(key);
        table[index].cretelist(key);
    }
    int hashFunction(int x) {

        return (x % BUCKET);
    }

    
};
