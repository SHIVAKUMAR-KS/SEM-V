const { Builder, By, until } = require('selenium-webdriver');
const chrome = require('selenium-webdriver/chrome');

async function runTest() {
    let driver = await new Builder().forBrowser('chrome').build();

    try {
        // Open the registration form
        await driver.get('http://localhost:3000');

        // Fill in the registration form
        await driver.findElement(By.id('username')).sendKeys('testuser');
        await driver.findElement(By.id('email')).sendKeys('testuser@example.com');
        await driver.findElement(By.id('password')).sendKeys('password123');

        // Submit the form
        await driver.findElement(By.tagName('button')).click();

        // Wait for the response
        await driver.wait(until.elementLocated(By.tagName('body')), 5000);

        // Verify the result
        let bodyText = await driver.findElement(By.tagName('body')).getText();
        if (bodyText.includes('Registration successful!')) {
            console.log('Test Passed: Registration was successful.');
        } else {
            console.log('Test Failed: Registration was not successful.');
        }
    } finally {
        await driver.quit();
    }
}

runTest();
