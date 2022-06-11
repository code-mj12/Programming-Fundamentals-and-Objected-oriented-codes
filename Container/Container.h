/*
 * Container.h
 *
 *  Created on: May 03,2020
 *      Author: Fatima
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_
#include<iostream>
using namespace std;

template<typename T>
class Container {
private:
        T * values;
        int capacity;
        int counter;
    public:
        Container(int c)
        {
        	values = new T[c];
        	capacity = c;
        	counter = 0;   
        }
        bool isFull( )
        {
	      if(counter == capacity)
	      {
	      	return true;
	      }
	      else
	      {
	      	return false;
	      }
        }
        void insert(T val)
        {
        if(counter < capacity)
	      {
	      	values[counter] = val;
	      	counter++;
	      }
	      else
	      {
		cout<<"FULL"<<endl;      
             	}
        }
        bool search( T  val)
        {
            for(int i=0; i<capacity; i++){
            	if(values[i] == val){
            	   return true;
            	}
            }
        }
        void remove(T val)
        {
           for(int i=0; i<capacity; i++){
            	if(values[i] == val){
                    for (int j = i; j < capacity-1; j++)
                    {
                        values[j]=values[j+1];
                    }
                    counter--;
                    cout<<"Value found"<<endl;
                    return;
            	}
            }
            cout<<"value not found"<<endl;
       }
       void Print( )
       {
            for (int i = 0; i < counter; i++)
            {
                cout<<"index "<<i<<" value is: "<<values[i]<<endl;
            }
                        
       }
};

#endif /* CONTAINER_H_ */
