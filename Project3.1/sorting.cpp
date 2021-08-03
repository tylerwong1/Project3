#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <chrono>
#include <time.h>
// struct created to store each entry from .csv file
struct Entry {
    std::string country;
    std::string date;
    std::unordered_map<std::string, int> data;
    Entry() {
        country = "";
        date = "";
        data["cases"] = 0;
        data["deaths"] = 0;
        data["vax"] = 0;
    }
    Entry(std::string country, std::string date, int cases, int vax, int deaths) {
        this->country = country;
        this->date = date;
        data["cases"] = cases;
        data["deaths"] = deaths;
        data["vax"] = vax;
    }
};
// This method is referenced from a previous lab assignment from COP3503
inline std::vector<Entry> readfiledata(std::string filename) {
    std::ifstream inFile(filename);
    std::vector<Entry> entries;
    std::string input;
    if (inFile.is_open()) {
        // ignores header titles
        std::getline(inFile, input);
        // sets entry values to ones in the file
        while (std::getline(inFile, input)) {
            Entry temp;
            std::string token;
            std::stringstream line(input);

            getline(line, token, ',');
            temp.country = token;

            getline(line, token, ',');
            temp.date = token;

            try {
                getline(line, token, ',');
                temp.data["cases"] = stoi(token);

                getline(line, token, ',');
                temp.data["deaths"] = stoi(token);

                getline(line, token, ',');
                temp.data["vax"] = stoi(token);
            }
            catch (std::invalid_argument()) {
                std::cout << "Error...Invalid Argument!" << std::endl;
            }
            // add entry to vector of entries
            entries.push_back(temp);
        }
    }
    else
        std::cout << "file could not be opened!" << std::endl;
    return entries;
}
//This method is based on the code from lecture 6j: quick sort code
inline int partition(std::vector<Entry>& entries, int low, int high, std::string category) {
    int pivot = entries[low].data[category];
    int up = low, down = high;
   
    while (up < down) {

        for (int i = up; i < high; i++) {
            // current element smaller than pivot
            if (entries[up].data[category] >= pivot)
                break;
            up++;
        }
        for (int i = high; i > low; i--) {
            if (entries[down].data[category] <= pivot)
                break;
            down--;
        }
        if (up < down) {
            // swapping entries for values
            std::swap(entries[up], entries[down]);
            if (entries[down].data[category] == pivot) {
                down--;
            }
            if (entries[up].data[category] == pivot) {
                up++;
            }
        }
    }
    std::swap(entries[low], entries[down]);
    return down;
}
//This method is based on the code from lecture 6j: quick sort code
inline void quickSort(std::vector<Entry>& quick, int low, int high, std::string category) {
    // depending on what data we are looking for, sort that specific data
    if (low < high) {
        // we need a partition index for quicksort
        int pi = partition(quick, low, high, category);
        quickSort(quick, low, pi, category);
        quickSort(quick, pi + 1, high, category);
    }

}
// This method is based on the code from lecture 5e: Heap Sort
inline void heapify(std::vector<Entry>& heap, int index, int size, std::string category)
{
    int largest = index;
    int l = (2 * index) + 1;
    int r = (2 * index) + 2;

    // check if the left child is greater
    if (l < size && heap[l].data[category] > heap[largest].data[category])
        largest = l;
    // check if the right child is greater
    if (r < size && heap[r].data[category] > heap[largest].data[category])
        largest = r;
    // if there was a child greater -> swap
    if (largest != index)
    {
        std::swap(heap[index], heap[largest]);
        heapify(heap, largest, size, category);
    }
}
// This method is based on the code from lecture 5e: Heap Sort
inline void heapSort(std::vector<Entry> &entries, std::string category) {
    //std::vector<Entry> heap = entries;
    // build
    for (int i = entries.size() / 2 - 1; i >= 0; i--)
        heapify(entries, i, entries.size(), category);
    // sort
    for (int i = entries.size() - 1; i > 0; i--)
    {
        std::swap(entries[0], entries[i]);
        heapify(entries, 0, i, category);
    }
    //return entries;
}
// This method is based on the code from lecture 6c: Bubble Sort
inline void optimizedBubbleSort(std::vector<Entry>& entries, std::string category, int outputs)
{
    int size = entries.size();
    int passes = 0;
    // size of vector is the max number of passes to fully sort
    for (int i = 0; i < size - 1; i++)
    {
        int swapcheck = 0;
        // max value placed at end of vector at end of each pass
        for (int j = 0; j < size - i - 1; j++)
        {
            // if left index is larger than right index -> swap them
            if (entries[j].data[category] > entries[j + 1].data[category])
            {
                // swap entries
                std::swap(entries[j], entries[j + 1]);
                swapcheck = 1;
            }
        }
        // for each pass the max value is placed at the end of the vector
        passes++;
        if (passes == outputs)
            break;
        // if there was no swap -> vector is sorted -> exit sort
        if (swapcheck == 0)
            break;
    }
}

//This method is based on the code from the Weiss data structures textbook on page 307 of chapter 7: sorting. figure 7.12 merge routine
//This merge sort doesn't create new subvectors for each pass, but instead just partitions a temporary vector
inline void merge(std::vector<Entry>& entries, std::vector<Entry>& tempvec, int left, int right, int rightend, std::string category) {
    int leftend = right - 1;
    int temppos = left;
    int elements = rightend - left + 1;
    //sorts the two subvectors while merging them
    while (left <= leftend && right <= rightend) {
        if (entries[left].data[category] <= entries[right].data[category]) {
            tempvec[temppos++] = (entries[left++]);
        }
        else {
            tempvec[temppos++] = (entries[right++]);
        }
    }
    //copies leftover elements from the left subvector
    while (left <= leftend) {
        tempvec[temppos++] = (entries[left++]);
    }
    //copies leftover elements from the right subvector
    while (right <= rightend) {
        tempvec[temppos++] = (entries[right++]);
    }
    //copies entire temporary vector back into the entered vector
    for (int i = 0; i < elements; ++i, --rightend) {
        entries[rightend] = tempvec[rightend];
    }
}

//This method is based on the code from the Weiss data structures textbook on page 306 of chapter 7: sorting. figure 7.11 mergeSort routine
inline void mergeSort(std::vector<Entry>& entries, std::vector<Entry>& tempvec, int left, int right, std::string category) {
    //if statement for base case when the subvector is only 1 element large
    if (left < right) {
        int middle = (left + right) / 2;
        //recursive calls on the left and right subvectors for mergesort
        mergeSort(entries, tempvec, left, middle, category);
        mergeSort(entries, tempvec, middle + 1, right, category);
        merge(entries, tempvec, left, middle + 1, right, category);
    }
}


inline std::vector<Entry> getData()
{
    // get data from csv file
    std::string filename = "coviddata.csv";
    std::vector<Entry> entries = readfiledata(filename);
    return entries;
}
