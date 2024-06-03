import csv
import pandas as pd
from vertex_ai import VertexAI, Model
from vertex_ai.models import SummarizationModel

# CSV 파일 읽기
data = pd.read_csv('data.csv')

# 텍스트 추출
text_list = data['텍스트 열 이름'].tolist()  # 텍스트 열 이름을 변경하세요.

# Vertex AI 클라이언트 생성
vertex_ai = VertexAI()

# 모델 로드
model = vertex_ai.models.SummarizationModel.load('YOUR_MODEL_ID')

# 요약 요청 생성
request = SummarizationModel.SummarizationRequest(
    text=text_list,
    return_detailed_summary=True  # 상세 요약 요청
)

# 요약 수행
response = model.predict(request)

# 요약 결과 출력
for summary in response.summaries:
    print(f"**요약:**")
    print(f"- 텍스트 길이: {summary.text_length}")
    print(f"- 요약 길이: {summary.summary_length}")

    # 열별 요약
    for column_summary in summary.column_summaries:
        print(f"- 열: {column_summary.column_name}")
        print(f"  - 통계 정보:")
        for stat in column_summary.statistics:
            print(f"    - {stat.name}: {stat.value}")
        print(f"  - 주요 내용:")
        for keypoint in column_summary.keypoints:
            print(f"    - {keypoint.text}")

    # 엔티티 인식
    if summary.entities:
        print(f"- 엔티티:")
        for entity in summary.entities:
            print(f"  - {entity.type}: {entity.text}")

    # 감정 분석
    if summary.sentiment:
        print(f"- 감정:")
        for sentiment_category in summary.sentiment:
            print(f"  - {sentiment_category.category}: {sentiment_category.score}")
