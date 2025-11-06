public class Minmax2d {
    // Function to find minimum
    public static void findMin(int[][] arr) {
        int min = arr[0][0];
        int row = 0, col = 0;

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if (arr[i][j] < min) {
                    min = arr[i][j];
                    row = i;
                    col = j;
                }
            }
        }

        System.out.println("Minimum = " + min + " at location (" + row + "," + col + ")");
    }

    // Function to find maximum
    public static void findMax(int[][] arr) {
        int max = arr[0][0];
        int row = 0, col = 0;

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if (arr[i][j] > max) {
                    max = arr[i][j];
                    row = i;
                    col = j;
                }
            }
        }

        System.out.println("Maximum = " + max + " at location (" + row + "," + col + ")");
    }

    public static void main(String[] args) {
        int[][] arr = {
            {4, 8, 3},
            {9, 1, 7},
            {6, 5, 2}
        };

        findMin(arr);
        findMax(arr);
    }
}