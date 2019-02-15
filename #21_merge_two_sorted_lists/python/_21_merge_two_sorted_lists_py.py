class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    
    def __init__(self):
        
        self.list_head = None
        self.list_tail = None
        
    def InsertNode(self, val):
        
        cur_node = ListNode(val)
        
        if self.list_head == None:
            self.list_head = cur_node 
            self.list_tail = cur_node
        else:
            self.list_tail.next = cur_node
            self.list_tail = self.list_tail.next
    
    def mergeTwoLists(self, l1, l2):
        
        if (l1 == None):
            return l2
        elif (l2 == None):
            return l1
        
        while(l1 != None and l2 != None):
            if (l1.val < l2.val):
                self.InsertNode(l1.val)
                l1 = l1.next
            else:
                self.InsertNode(l2.val)
                l2 = l2.next
                
        if (l1 != None):
            while(l1 != None):
                self.InsertNode(l1.val)
                l1 = l1.next
        elif (l2 != None):
            while(l2 != None):
                self.InsertNode(l2.val)
                l2 = l2.next
                
        return self.list_head

def main():

    list1 = [1,2,4]
    list2 = [1,3,4]

    list1_head = None
    list2_head = None 
    list1_tail = None 
    list2_tail = None
 
    for i in range(3):
        cur_node1 = ListNode(list1[i])
        cur_node2 = ListNode(list2[i])

        if (list1_head == None):
            list1_head = list1_tail = cur_node1
        else:
            list1_tail.next = cur_node1
            list1_tail = list1_tail.next

        if (list2_head == None):
            list2_head = list2_tail = cur_node2
        else:
            list2_tail.next = cur_node2
            list2_tail = list2_tail.next


    Sol = Solution()

    merged_list = Sol.mergeTwoLists(list1_head, list2_head)

    while(merged_list != None):
        print(merged_list.val)
        merged_list = merged_list.next

    return 

if __name__ == '__main__':
    main()