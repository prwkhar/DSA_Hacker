 if (position == 0) { // Special case: inserting at the head
        new_node->next = llist;
        return new_node;
    }

Remember about position 0 when head is changed