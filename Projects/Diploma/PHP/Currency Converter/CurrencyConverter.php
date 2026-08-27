<?php
function convertCurrency($amount, $fromCurrency, $toCurrency)
{
    $exchangeRates = [
        'USD' => 1.0,
        'EUR' => 0.85,
        'JPY' => 110.0,
        'GBP' => 0.75,
        'AUD' => 1.35,
        'CAD' => 1.25,
        'CHF' => 0.92,
        'CNY' => 6.45,
        'INR' => 74.0,
        'BRL' => 5.25
    ];

    if (!is_numeric($amount) || $amount <= 0) 
    {
        return "Please enter a valid numeric amount.";
    }

    if (!array_key_exists($fromCurrency, $exchangeRates) || !array_key_exists($toCurrency, $exchangeRates)) 
    {
        return "Please select valid currencies.";
    }

    $amountInUSD = $amount / $exchangeRates[$fromCurrency];
    $convertedAmount = $amountInUSD * $exchangeRates[$toCurrency];

    return sprintf("%.2f %s = %.2f %s", $amount, $fromCurrency, $convertedAmount, $toCurrency);
}

echo "Welcome to the Currency Converter!\n";
echo "Enter the amount: ";
$amount = trim(fgets(STDIN));

echo "From Currency (USD, EUR, JPY, GBP, AUD, CAD, CHF, CNY, INR, BRL): ";
$fromCurrency = trim(fgets(STDIN));

echo "To Currency (USD, EUR, JPY, GBP, AUD, CAD, CHF, CNY, INR, BRL): ";
$toCurrency = trim(fgets(STDIN));

$result = convertCurrency($amount, $fromCurrency, $toCurrency);
echo $result . "\n";
?>