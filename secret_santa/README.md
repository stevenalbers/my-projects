#Secret Santa Generator
###About
This is a slightly modified version of a program I had written a while back which automates the annual process of selecting Secret Santas for my family's Christmas party. For each participant, a Secret Santa recipient is selected at random given the criteria that

1. They do not belong to the same immediate family
2. They have not already been chosen

The algorithm I use is fairly efficient (O(n)), but does not successfully randomize the list each time. Because the algoritm is greedy, it is possible for two members of the same family to be the only remaining unselected participants. At present it's a simple fix to just rerun the program, but I'm deciding on a more elegant solution to deploy in the near future.

###Usage
Type "make" to build the project, and execute it. The result is dropped in "output.txt"

###Future Development
1. The first fix I'd like to implement would be solving the infinite loop problem I'm facing. A simple but inefficient brute-force approach I could take is to add a timeout (~100 failed attempts) to the randomization function, then restart the process until a successful list is created.
2. Currently, the Secret Santa mods must individually e-mail each participant covertly with their chosen recipient. It would be nice if I could shoot that e-mail out for them by attaching an e-mail member to the person struct. I'd also have to make the program network-worthy, either through SMTP or libcurl.
3. It would be nice of me to share this with the world! I'd like to modularize the program to accept any family by allowing users to edit family lists and have the program run just the same. The most user-friendly option I've come up with is to include a directory with the program containing x number of family files the user can edit freely. The program would then have a spider crawl through that directory and dynamically populate the randomization list.
