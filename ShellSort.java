//Implement shell sort in java

//import java.io.*;
import java.util.Scanner;

class ShellSort {
	static void printArray(int arr[]) {
		int n = arr.length;
		for (int i = 0; i < n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	int sort(int arr[]) {
		int n = arr.length;

		for (int gap = n / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < n; i += 1) {
				int temp = arr[i];
				int j;
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
					arr[j] = arr[j - gap];

				arr[j] = temp;
			}
		}
		return 0;
	}

	public static void main(String args[]) {
		int n, i;

		Scanner s = new Scanner(System.in);

		System.out.println("Enter size of array:");
		n = s.nextInt();

		int arr[] = new int[n];

		System.out.println("Enter the elements of array:");
		for (i = 0; i < n; i++) {
			arr[i] = s.nextInt();
		}

		System.out.println("Array before sorting");
		printArray(arr);

		ShellSort ob = new ShellSort();
		ob.sort(arr);

		System.out.println("Array after sorting");
		printArray(arr);

	}
}
