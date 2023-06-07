const CDP = require('chrome-remote-interface');

CDP((client) => {
  // Extract used DevTools domains.
  const { Network, Page } = client;

  // Enable events on domains we are interested in.
  Promise.all([Network.enable(), Page.enable()]).then(() => {
    // Prepare the script to be evaluated on the page.
    const script = `
      const MAX_VISIT_COUNT=10, visitCount=0, visitStustFlip=()=>visitCount>=MAX_VISIT_COUNT?(console.log('MAX_VISIT_COUNT reached!'),clearInterval(intervalId)):fetch('https://flipclass.stust.edu.tw/media/doc/181697').then(e=>(console.log(\`num \${visitCount+1} times success\`),visitCount++)).catch(e=>(console.error(\`num \${visitCount+1} times fail\${e}\`),visitCount++)),intervalId=setInterval(visitStustFlip,500);
    `;

    // Evaluate the script.
    Page.addScriptToEvaluateOnNewDocument({ source: script });

    // Navigate to the page.
    Network.navigate({ url: 'https://flipclass.stust.edu.tw/course/material/24886' });

    // Wait for the page to load.
    Page.loadEventFired(() => {
      console.log('Page loaded');
      // Close the client.
      client.close();
    });
  }).catch((err) => {
    console.error('Error:', err);
    client.close();
  });
}).on('error', (err) => {
  console.error('Cannot connect to browser:', err);
});
