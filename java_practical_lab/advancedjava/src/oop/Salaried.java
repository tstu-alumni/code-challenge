package oop;

/**
 * Created by alex on 20/09/16.
 */
public class Salaried extends Employee {
    public static final double DEFAULT_SALARY = 120000;

    private double salary = DEFAULT_SALARY;

    /*
     * Calls super() be default
     */
    public Salaried(){}

    /*
    public Salaried(){
        this(Employee.DEFAULT_NAME, Salaried.DEFAULT_SALARY);
    }
    */
    public Salaried(String name){
        this(name, DEFAULT_SALARY);
    }

    public Salaried(String name, double salary){
        super(name);
        this.salary = salary;
    }

    public double getSalary(){
        return salary;
    }

    public void setSalary(double salary){
        this.salary = salary;
    }

    @Override
    public double getPay() {
        return salary / 24;
    }
}
