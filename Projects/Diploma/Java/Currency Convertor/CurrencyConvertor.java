import java.util.Scanner;


class CurrencyConverter 
{
    public static void main(String[] args) 
    {

        double UsdToINRRate = 83.06;
        double UsdToEURRate = 0.93;
        double UsdToDIRRate = 3.67;

        Scanner scanner = new Scanner(System.in);

        System.out.println("********Welcome to Currency Converter*******");
        System.out.println("Enter the amount in USD:");
        double amountInUSD = scanner.nextDouble();

        double amountInINR = amountInUSD * UsdToINRRate;
        double amountInEUR = amountInUSD * UsdToEURRate;
        double amountInDIR = amountInUSD * UsdToDIRRate;

        System.out.println("\nConverted Amounts:");
        System.out.println("Indian Rupee (INR): " + amountInINR);
        System.out.println("Euro (EUR): " + amountInEUR);
        System.out.println("United States of Emirates (DIR): " + amountInDIR);

        scanner.close();
    }
}
