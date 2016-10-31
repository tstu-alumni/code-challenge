package oop;

import java.time.LocalDate;

/**
 * Created by alex on 20/09/16.
 */
public abstract class Employee {
    public static final String DEFAULT_NAME = "UKNOWN";
    private static int nextId;

    private Integer id;
    private String name;
    private LocalDate hireDate;

    public Employee(){
        this(DEFAULT_NAME);
    }

    public Employee(String name){
        id = nextId++;
        this.name = name;
        hireDate = LocalDate.now();
    }

    public Integer getId(){
        return id;
    }

    private void setId(Integer id){
        this.id = id;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    public LocalDate getHireDate(){
        return hireDate;
    }

    public abstract double getPay();

    @Override
    public String toString(){
        return String.format("Employee{id=%d, name='%s', hireDate='%s'}", id, name, hireDate);
    }
}
