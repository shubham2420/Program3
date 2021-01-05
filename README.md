# Program3

CSS342-Project3

This assignment is designed to give you in depth experience with linked lists. You will build a ledger that keeps track of transactions. You can both add payments and issue refunds. You will also need to implement some printing functions to examine the list. You need to create your own linked list -- don't use std::list. You will implement the following functionality:

Constructor -- Creates a new, empty linked list Destructor -- Cleans up all of the allocated memory

// Editing the ledger

AddExternalMoney(ToName, Amount) -- Adds Amount money to the system in the name of ToName user.

AddPayment(FromName, ToName, Amount) -- enters a transfer from FromName to ToName in the amount of Amount. FromName now has Amount less money and ToName now has Amount more money. Returns the transaction Id.

RefundPayment(Id), RefundPayment(FromName, ToName, Amount) -- Deletes the node referred to by either the Node Id or the exact match of FromName, ToName, and Amount. If the node isn't found, returns -1.

Clear() -- Removes all of the transactions.

// Printing the ledger

Print(), Print(UserName) -- Prints the entire ledger, optionally the ledger for only a specific user Settle() -- Prints the name and balance of each user InTheBlack() -- Prints the name and balance of each user who has positive money InTheRed() -- Prints the name and balance of each user who has negative money

Each Node needs a unique integer Id in addition to its link(s) to other nodes.

You will submit the following files in program3.zip:

LedgerDriver.cpp
Ledger.h
Ledger.cpp
If you have other files as part of your implementation, please include them as well.

Grading Rubric:

To receive full credit, your code must compile in CSS UNIX labs, it must not segfault or run indefinitely. Implemented function names must match above (including capitalizations). Functions must accept exactly the stated parameters as above. Do not add more or omit parameters. Do not leave debug statements in your code or the grader will deduct points at his discretion.

Constructor/Destructor -- 8 points (4 each) Editing functions -- 20 points (5 each) Printing functions -- 12 points (3 points each)

Readable coding style and all .h/.cpp functions documented -- 10 points
