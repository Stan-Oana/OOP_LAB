// TemperatureConverter.h
#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

// Function prototypes
double CelsiusToFahrenheit(double celsius);
double FahrenheitToCelsius(double fahrenheit);

// Function to convert Celsius to Fahrenheit
double CelsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to convert Fahrenheit to Celsius
double FahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

#endif // TEMPERATURECONVERTER_H#pragma once