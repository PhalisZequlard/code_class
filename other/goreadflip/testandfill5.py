import time
import webbrowser
from selenium import webdriver
MAX_VISIT_COUNT = 10
visitCount = 0
driver = webdriver.Chrome()
def visitStustFlip():
    global visitCount
    if visitCount >= MAX_VISIT_COUNT:
        print("MAX_VISIT_COUNT reached!")
        return False
    row_num = visitCount + 1
    row_selector = f"tbody > tr:nth-child({row_num})"
    popularity_selector = row_selector + " > td.col-num"
    popularity = int(driver.find_element_by_css_selector(popularity_selector).text)
    if popularity % 5 == 0:
        visitCount += 1
        return True
    link_selector = row_selector + " > td:nth-child(2) > div > div.fs-singleLineText > div.text-overflow > a"
    link = driver.find_element_by_css_selector(link_selector).get_attribute("href")
    for i in range(popularity % 5):
        webbrowser.open(link)
    visitCount += 1
    return True
driver.get("https://flipclass.stust.edu.tw/course/material/24886")
while visitStustFlip():
    time.sleep(1)

driver.quit()
