import vertex_ai as vertex

# API 키 설정
api_key = "YOUR_API_KEY"

# Vertex AI 클라이언트 생성
client = vertex.ApiClient(api_key)

# 요약할 텍스트 설정
text = "요약할 텍스트를 입력하세요."

# 텍스트 요약
response = client.models.summarize_text(text)

# 요약 텍스트 출력
print(response.summary)
