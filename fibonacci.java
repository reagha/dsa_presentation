class FibonacciDP {
    static int[] memo;

    static int fib(int n) {
        if (n <= 1) return n;

        // if result already computed
        if (memo[n] != -1) return memo[n];

        // compute and store
        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }

    public static void main(String[] args) {
        int n = 10;
        memo = new int[n + 1];

        
        for (int i = 0; i <= n; i++) memo[i] = -1;

        System.out.println("Fibonacci of " + n + " is " + fib(n));
    }
}
