public class Merged {
    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4};
        int[] arr2 = {5, 6, 7};

        int size1 = arr1.length;
        int size2 = arr2.length;

        int[] merged = new int[size1 + size2];

        // Copy arr1
        for (int i = 0; i < size1; i++) {
            merged[i] = arr1[i];
        }

        // Copy arr2
        for (int j = 0; j < size2; j++) {
            merged[size1 + j] = arr2[j];
        }

        // Print merged array
        System.out.print("Merged Array: ");
        for (int num : merged) {
            System.out.print(num + " ");
        }
    }
}

