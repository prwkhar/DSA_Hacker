The main code is just this
while(current!=nullptr)
{
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
}
we are storing next of current
and changing current next to prev
