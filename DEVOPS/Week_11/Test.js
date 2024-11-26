//npx http-server

const { Builder, By, Key, until } = require('selenium-webdriver');

async function testRegistrationForm() {
    // Set up WebDriver
    let driver = await new Builder().forBrowser('chrome').build();
    try {
        // Navigate to the registration form
        await driver.get('http://localhost:8080');

        // Enter username
        await driver.findElement(By.id('username')).sendKeys('student1');

        // Enter email
        await driver.findElement(By.id('email')).sendKeys('student1@example.com');

        // Enter password
        await driver.findElement(By.id('password')).sendKeys('password123');

        // Click the Register button
        await driver.findElement(By.css('button[type="submit"]')).click();

        // Wait for the success message to appear
        await driver.wait(until.elementLocated(By.id('message')), 5000);

        // Get the message text
        let message = await driver.findElement(By.id('message')).getText();
        console.log('Test Result:', message);

        // Check if registration is successful
        if (message === 'Registration Successful!') {
            console.log('Test Passed');
        } else {
            console.log('Test Failed');
        }
    } finally {
        // Close the browser
        await driver.quit();
    }
}

testRegistrationForm();
