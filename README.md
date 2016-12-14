# Bank-Queue-management
Assume we have a very small bank which has only two teller lines to service customers. Customers wait in one line (queue) as they enter the bank and then are called to the next available teller.
Each teller window is a queue of ONE person (tellerone queue and tellertwo queue). The queue to get waited on (main teller queue) holds six people and there is a second queue of six people outside the door (outside queue) waiting to get into the teller queue.
Each queue is a queue of CHARACTER..use a one character id for each person..the id can be a letter, digit or punctuation mark.
Write a simulation to show this using the following:
1. an arrival function..people arrive in the MAIN teller queue and as room is available in either of the teller queues, the person leaves the main teller queue and arrives into whichever teller queue has room.
2. a departure function…when a person departs either teller queue, whoever is at the front of the main teller queue departs that queue and arrives into the teller queue having room
3. if more than six people arrive at once the the outside queue starts to fill and as people exit the main teller queue the person in front of the outside queue departs that queue and enters the main queue.
This MUST be interactive.
