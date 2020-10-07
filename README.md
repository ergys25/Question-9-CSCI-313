# Question-9-CSCI-313


A program that finds if a random sequence is a De Bruijn sequence.


## Main function 
I create a random array of size k and I also create an array of size 2^k that holds all the possible combinations if i shift the sequence by one space

```C++
int main() {
    int k;
    bool unique = false;
    std::cout << "Please enter k:" << std::endl;
    std::cin >> k;
    auto *comb = new std::string[pow(2,
                                     k)]; // creating an array of size 2^k to use to store each possible k digit combination. Each combination is  shifted by one.
    auto *DB = new std::string[pow(2, k)]; // creating an array of size 2^k to store the sequence
    srand(static_cast<unsigned int>(time(nullptr)));
    auto start = high_resolution_clock::now(); //start time to measure performance execution
    randomizer(DB, k);
    combinations(comb, DB,
                 k); // create all the possible k length combinations from the sequence shifting the array by one. The sequence is circular.
    
```
## If all the combinations of substrings are unique then the sequence is a De Bruijn sequence
```C++
while (!unique) {
        for (int(i) = 0; (i) < pow(2, k); i++) { // compare all the entries on the combination array with each other
            for (int j = i + 1; j < pow(2, k); j++) {
                if (comb[i] == comb[j]) { // if there exist already a combination
                    combClear(comb, k); //clear the combination array
                    randomMutate(DB,
                                 k); // randomize again the sequence by giving a random number of mutates and by giving a random position on the array
                    combinations(comb, DB, k); // create a new combination array
                    i = -1;
                    break;
                }

            }


        }
        unique = true;
    }
    auto stop = high_resolution_clock::now(); //end time of execution performance measurement
    auto duration = duration_cast<microseconds>(stop - start);'

```

## Linked List
Here is the same procedure only I am using linked list to create the sequence and to store the substring on the combination array 
```C++

start = high_resolution_clock::now();
    queue sequence;
    for (int i = 0; i < pow(2, k); i++) { // fill the linked list with a random sequence
        sequence.addTail(randomStringGenerator());
    }
    node *temp; // store the sequence to an array
    temp = sequence.getHead();
    int i = 0;
    while (temp != NULL) {
        DB[i] = temp->data;
        i++;
        temp = temp->next;
    }
    combinations(comb, DB, k); // create all possible combination
    unique = false;
    while (!unique) {
        for (int(i) = 0; (i) < pow(2, k); i++) { // compare all the entries on the combination array with each other
            for (int j = i + 1; j < pow(2, k); j++) {
                if (comb[i] == comb[j]) { // if there exist already a combination
                    combClear(comb, k); //clear the combination array
                    int power = pow(2, k);
                    int change = rand() % (power + 1 - 1) + 1; // number of switches to be performed
                    int mutation =
                            rand() % (power + 1 - 0) +
                            0; // where at random on the linked list the switch will be performed
                    temp = sequence.getHead();
                    for (int c = 0; c < change; c++) {
                        for (int m = 0; m < mutation - 1; m++) {
                            temp = temp->next;
                        }
                        if (temp->data == "1") { //if the character in the sequence is 1 switch to 0
                            temp->data = "0";
                            mutation = rand() % (power + 1 - 0) + 0;// create a new random point
                            temp = sequence.getHead(); // go back to head
                        } else {
                            temp->data = "1"; // if the character in the sequence is 0 switch to 1
                            mutation = rand() % (power + 1 - 0) + 0; // create a new random point
                            temp = sequence.getHead(); // go back to head
                        }
                    }

                    temp = sequence.getHead(); //  fill the sequence array
                    int s = 0;
                    while (temp != NULL) {
                        DB[s] = temp->data;
                        temp = temp->next;
                        s++;
                    }
                    combinations(comb, DB, k); // create a new combination array
                    i = -1;
                    break;
                }

            }


        }
        unique = true;
    }
    stop = high_resolution_clock::now();
```


## Conclusion
Even though I am  using RNG to create the sequence and RNG to change it if the entries on the combination array are not unique we can see that the array is faster that the linked list since it supports random access while on the linked list we have to travers it every time we want to make a change
