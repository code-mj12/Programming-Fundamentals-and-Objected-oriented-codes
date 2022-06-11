/*
 * C++ Program to Implement Stack in Stl
 */
#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

void menu() {
    cout<<endl;
    cout<<"Enter 1 to insert element into the stack."<<endl;
    cout<<"Enter 2 to delete element from the stack."<<endl;
    cout<<"Enter 3 to display size of the stack."<<endl;
    cout<<"Enter 4 to display top element of the stack."<<endl;
    cout<<"Enter 5 to exit."<<endl;
    cout<<endl;
}


int main()
{
    stack<int> st;
    int choice, item;
    while (1)
    {
        
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter integer to insert: ";
            cin>>item;
            st.push(item);
            break;
        case 2:
            if(st.size()>0) {
				st.pop();
				cout<<"Element deleted."<<endl;
			} else {
				cout<<"No elements in stack."<<endl;
			}
            break;
        case 3:
            cout<<"Stack Size: "<<st.size()<<endl;
            break;
        case 4:
	    if(st.size()>0) {
				cout<<"Top Element in Stack: "<<st.top()<<endl;
			} else {
				cout<<"No elements in stack."<<endl;
			}
            break;
        case 5:
        	cout<<"Session ended";
            exit(1);
	    break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
