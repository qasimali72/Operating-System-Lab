//Take input the height and width of rectangle and find its area and perimeter(2*L +
//2*W) using multiple threads. Print thread ID of multiple thread using function. Adjust
//the output in specified sequence using join function.


#include <stdio.h>
#include <pthread.h>

// Structure to pass data to the threads
struct RectangleData {
  double length;
  double width;
  double area;
  double perimeter;
};

// Function to calculate the area of the rectangle
void *calculate_area(void *arg) {
  struct RectangleData *data = (struct RectangleData *)arg;
  data->area = data->length * data->width;
  pthread_exit(NULL);
}

// Function to calculate the perimeter of the rectangle
void *calculate_perimeter(void *arg) {
  struct RectangleData *data = (struct RectangleData *)arg;
  data->perimeter = 2 * (data->length + data->width);
  pthread_exit(NULL);
}

int main() {
  // Get user input for the length and width of the rectangle
  struct RectangleData data;
  printf("Enter the length of the rectangle: ");
  scanf("%lf", &data.length);
  printf("Enter the width of the rectangle: ");
  scanf("%lf", &data.width);

  // Create threads for calculating area and perimeter
  pthread_t thread_area, thread_perimeter;

  // Initialize and create threads
  pthread_create(&thread_area, NULL, calculate_area, (void *)&data);
  pthread_create(&thread_perimeter, NULL, calculate_perimeter, (void *)&data);

  // Wait for both threads to finish
  pthread_join(thread_area, NULL);
  pthread_join(thread_perimeter, NULL);

  // Get the results from the structure
  double area = data.area;
  double perimeter = data.perimeter;

  printf("Area of the rectangle: %lf\n", area);
  printf("Perimeter of the rectangle: %lf\n", perimeter);

pthread_t thread_id = pthread_self();
  printf("Main thread ID: %lu\n", thread_id);

  return 0;
}
