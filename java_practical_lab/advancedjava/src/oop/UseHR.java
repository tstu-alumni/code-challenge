package oop;

/**
 * Created by alex on 20/09/16.
 */
public class UseHR {
    public static void main(String[] args){
        HR hr = new HR();
        hr.hire(new Salaried("Fred"));
        //hr.hire(new Hourly("Berney"));
        hr.hire(new Salaried());
        //hr.hire(new Hourly());
        hr.printEveryBody();
        hr.payEveryBody();
    }
}
