import csv
import pandas as pd
from vertex_ai import VertexAI, Model
from vertex_ai.models import SummarizationModel

# CSV ���� �б�
data = pd.read_csv('data.csv')

# �ؽ�Ʈ ����
text_list = data['�ؽ�Ʈ �� �̸�'].tolist()  # �ؽ�Ʈ �� �̸��� �����ϼ���.

# Vertex AI Ŭ���̾�Ʈ ����
vertex_ai = VertexAI()

# �� �ε�
model = vertex_ai.models.SummarizationModel.load('YOUR_MODEL_ID')

# ��� ��û ����
request = SummarizationModel.SummarizationRequest(
    text=text_list,
    return_detailed_summary=True  # �� ��� ��û
)

# ��� ����
response = model.predict(request)

# ��� ��� ���
for summary in response.summaries:
    print(f"**���:**")
    print(f"- �ؽ�Ʈ ����: {summary.text_length}")
    print(f"- ��� ����: {summary.summary_length}")

    # ���� ���
    for column_summary in summary.column_summaries:
        print(f"- ��: {column_summary.column_name}")
        print(f"  - ��� ����:")
        for stat in column_summary.statistics:
            print(f"    - {stat.name}: {stat.value}")
        print(f"  - �ֿ� ����:")
        for keypoint in column_summary.keypoints:
            print(f"    - {keypoint.text}")

    # ��ƼƼ �ν�
    if summary.entities:
        print(f"- ��ƼƼ:")
        for entity in summary.entities:
            print(f"  - {entity.type}: {entity.text}")

    # ���� �м�
    if summary.sentiment:
        print(f"- ����:")
        for sentiment_category in summary.sentiment:
            print(f"  - {sentiment_category.category}: {sentiment_category.score}")
