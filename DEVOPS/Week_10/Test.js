const { Builder, By, Key, until } = require('selenium-webdriver');

async function testGoogleSearch() {
    // Step 1: Launch the Chrome browser
    let driver = await new Builder().forBrowser('chrome').build();
    try {
        // Step 2: Open the Google homepage
        await driver.get('https://www.google.com');

        // Step 3: Locate the search box and enter a search query
        await driver.findElement(By.name('q')).sendKeys('Selenium WebDriver', Key.RETURN);

        // Step 4: Wait for the search results to load
        await driver.wait(until.titleContains('Selenium WebDriver'), 5000);

        // Step 5: Print the page title in the console
        let title = await driver.getTitle();
        console.log('Page Title:', title);

        // Step 6: Check if the search results are displayed
        if (title.includes('Selenium WebDriver')) {
            console.log('Test Passed: Search results loaded successfully.');
        } else {
            console.log('Test Failed: Search results not loaded.');
        }
    } catch (error) {
        console.error('Error:', error);
    } finally {
        // Step 7: Close the browser
        await driver.quit();
    }
}

testGoogleSearch();
