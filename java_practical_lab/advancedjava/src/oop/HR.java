package oop;

import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by alex on 20/09/16.
 */
public class HR {
    private List<Employee> employees = new ArrayList<>();

    public void hire(Employee e){
        employees.add(e);
    }

    public void layoff(Employee e){
        employees.remove(e);
    }

    public List<Employee> getEmployees(){
        return  employees;
    }

    public void printEveryBody(){
        /*
         * Lambda
         */
        employees.forEach(System.out::println);
    }

    public void payEveryBody(){
        for (Employee e : employees){
            System.out.printf("Paying %s %s%n", e.getName(), NumberFormat.getCurrencyInstance().format(e.getPay()));
        }
    }
}
