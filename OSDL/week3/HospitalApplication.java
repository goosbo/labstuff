package week3;

class DoctorService extends Thread {
    public void run(){
        System.out.println("Doctor consulting patient - "+Thread.currentThread().getName());
    }
}

class NurseService extends Thread {
    public void run(){
        System.out.println("Nurse providing care - "+ Thread.currentThread().getName());
    }
}

class BillingService extends Thread {
    public void run(){
        System.out.println("Billing process started - "+ Thread.currentThread().getName());
    }
}

public class HospitalApplication {
    public static void main(String[] args) {
        System.out.println("Hospital services started");
        DoctorService doctor = new DoctorService();
        NurseService nurse = new NurseService();
        BillingService billing = new BillingService();

        doctor.start();
        nurse.start();
        billing.start();

        System.out.println("Hospital service running concurrently");
    }
    
}
