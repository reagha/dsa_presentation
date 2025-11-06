public class Arrays3d {
    public static void main(String[] args) {
        int[][][] arr = {
            {
                {10, 20, 30, 40, 50},
                {60, 70, 80, 90, 100}
            },
            {
                {10, 20, 30, 40, 50},
                {60, 70, 80, 90, 100}
            }
        };

        System.out.println("Base address (hashcode) of arr: " + arr);

        System.out.println("3D Array Traversal:");
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                for (int k = 0; k < arr[i][j].length; k++) {
                    System.out.println("arr[" + i + "][" + j + "][" + k + "] = " + arr[i][j][k]);
                }
            }
        }
    }
}
