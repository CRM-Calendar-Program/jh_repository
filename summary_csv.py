import csv
import pandas as pd
from gensim.summarization import summarize

# CSV ���� �б�
data = pd.read_csv('data.csv')

# ����� �ؽ�Ʈ ����
text = data['�ؽ�Ʈ �� �̸�'].tolist()  # �ؽ�Ʈ �� �̸��� �����ϼ���.

# �ؽ�Ʈ ���
summary = summarize(text)

# ��� ���
print(summary)
