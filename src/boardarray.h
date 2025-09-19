#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT

            if(index < SIZE){
                array[index] = *entry;
                index++;
            }else{
                for(int i = 0; i<index; i++){
                    if (entry -> compare(&array[i])){
                        for(int j = SIZE;j > 0; j--){
                            array[i] = array[i - 1];
                        }
                    }
                }
            }
            
            return;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }

        
};