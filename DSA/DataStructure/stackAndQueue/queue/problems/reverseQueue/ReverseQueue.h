#ifndef REVERSEQUEUE_H
#define REVERSEQUEUE_H

#include <stdio.h>
#include "../linkedListQueue/LinkedListQueue.h"
#include "../../stack/linkedListStack/LinkedListStack.h"

// - Time Complexity: O(n). 
// - Space Complexity: O(n)
void reverseQueueFirstKElement(int k, Queue *queue);

#endif
