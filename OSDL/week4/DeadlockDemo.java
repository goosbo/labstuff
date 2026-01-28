package week4;

class DeadlockDemo {
    // Two shared resources
    static final Object resource1 = new Object();
    static final Object resource2 = new Object();
    // Thread 1
    static class ThreadA extends Thread {
        @Override
        public void run() {
            synchronized (resource1) {
                System.out.println("Thread A locked Resource 1");
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    System.out.println("Thread A interrupted");
                }
                System.out.println("Thread A waiting for Resource 2");
                synchronized (resource2) {
                    System.out.println("Thread A locked Resource 2");
                }
            }
        }
    }
    // Thread 2
    static class ThreadB extends Thread {
        @Override
        public void run() {
            synchronized (resource2) {
                System.out.println("Thread B locked Resource 2");
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    System.out.println("Thread B interrupted");
                }
                System.out.println("Thread B waiting for Resource 1");
                synchronized (resource1) {
                    System.out.println("Thread B locked Resource 1");
                }
            }
        }
    }
    // Main method
    public static void main(String[] args) {
        Thread t1 = new ThreadA();
        Thread t2 = new ThreadB();
        t1.start();
        t2.start();
    }
}