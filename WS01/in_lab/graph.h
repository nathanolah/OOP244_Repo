// Nathan Olah 
// Student Number: 124723198
// September 11, 2019

#ifndef SDDS_GRAPH_H__
#define SDDS_GRAPH_H__

#define MAX_NO_OF_SAMPLES 20
#define GRAPH_WIDTH 65

namespace sdds
{
   // Fills the samples array with the statistic samples
   void getSamples(int samples[], int noOfSamples);
   // Finds the largest sample in the samples array, if it is larger than 70,
   // otherwise it will return 70. 
   int findMax(int samples[], int noOfSamples);
   // Prints a scaled bar relevant to the maximum value in samples array
   void printBar(int val, int max);
   // Prints a graph comparing the sample values visually 
   void printGraph(int samples[], int noOfSamples);
}

#endif