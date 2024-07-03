
#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};


void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node){ 
  /* Add head and tail for me please */
  if(headPtr!=NULL) tailPtr->set_next(new_node); //if(size==0)

  //2. (may be) change head  when the queue is empty
  else headPtr=new_node;
  
  tailPtr=new_node;

  /*
  if(headPtr!=NULL)
  {
    tailPtr->set_next(new_node);
    tailPtr=tailPtr->get_next();
  }
  else
  {
    headPtr=new_node;
    tailPtr=new_node;
  }*/
  
  //3. increase size*/
  size++;
	
 }
}

int Queue::dequeue(){
  if(headPtr!=NULL){
     NodePtr t=headPtr;
     int value= t->get_value();
     /* Add head and tail for me please */
     if(size==1)
     {
        headPtr=NULL;
        tailPtr=NULL;
     }
     else headPtr=headPtr->get_next();

     size--;
          
     delete t;
     return value;
  }
  
  cout<<"Empty queue"<<endl;
  return -1;
}


Queue::Queue(){
    //initialize Queue
    size=0;
    headPtr=NULL;
    tailPtr=NULL;
    
}
Queue::~Queue(){
    //delete all remaning Queue (i.e. DQ all) 
    cout<<"Clearing queue"<<endl;
    NodePtr t;
    for (int i=0; i<size; i++)
    {
        t=headPtr;
        headPtr=headPtr->get_next();

        cout<<"Dequeing "<<t->get_value()<<endl;
        delete t;
    }
    
}


#endif
