import csv
import pandas as pd
from gensim.summarization import summarize

# CSV 파일 읽기
data = pd.read_csv('data.csv')

# 요약할 텍스트 추출
text = data['텍스트 열 이름'].tolist()  # 텍스트 열 이름을 변경하세요.

# 텍스트 요약
summary = summarize(text)

# 요약 출력
print(summary)
