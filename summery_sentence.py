import vertex_ai as vertex

# API Ű ����
api_key = "YOUR_API_KEY"

# Vertex AI Ŭ���̾�Ʈ ����
client = vertex.ApiClient(api_key)

# ����� �ؽ�Ʈ ����
text = "����� �ؽ�Ʈ�� �Է��ϼ���."

# �ؽ�Ʈ ���
response = client.models.summarize_text(text)

# ��� �ؽ�Ʈ ���
print(response.summary)
