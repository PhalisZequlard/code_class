const MAX_VISIT_COUNT = 50;
let visitCount = 0;
function visitStustFlip() {
  if (visitCount >= MAX_VISIT_COUNT) {
    console.log("MAX_VISIT_COUNT reached!");
    clearInterval(intervalId);
    return;
  }
  fetch("https://flipclass.stust.edu.tw/media/doc/183300")
    .then(response => {
      console.log(`no:${visitCount + 1} success`);
      visitCount++;
    })
    .catch(error => {
      console.error(`num ${visitCount + 1} fail${error}`);
      visitCount++;
    });
}
const intervalId = setInterval(visitStustFlip, /*1000*/200);