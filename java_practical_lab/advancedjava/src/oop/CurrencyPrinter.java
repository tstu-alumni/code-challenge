package oop;

import java.text.NumberFormat;
import java.util.Locale;

/**
 * Created by alex on 20/09/16.
 */
public class CurrencyPrinter {
    public static void main(String[] args){
        double amount = 1234567.8901234;
        /*
         * Factory method
         */
        NumberFormat nf = NumberFormat.getCurrencyInstance();
        System.out.println(nf.format(amount));

        nf = NumberFormat.getCurrencyInstance(Locale.FRANCE);
        System.out.println(nf.format(amount));

        System.out.println(nf.getClass().getName());
    }
}
