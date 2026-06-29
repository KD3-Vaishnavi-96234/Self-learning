<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="jakarta.tags.core"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<style>
body {
	font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto,
		Helvetica, Arial, sans-serif;
	background-color: #f8f9fa;
	color: #212529;
	display: flex;
	justify-content: center;
	align-items: center;
	height: 100vh;
	margin: 0;
}

.form-container {
	background: #ffffff;
	padding: 30px;
	border-radius: 8px;
	box-shadow: 0 4px 12px rgba(0, 0, 0, 0.05);
	width: 100%;
	max-width: 400px;
}

h2 {
	margin-top: 0;
	margin-bottom: 20px;
	font-size: 24px;
	font-weight: 600;
	color: #1a1a1a;
	text-align: center;
}

label {
	display: block;
	font-size: 14px;
	font-weight: 500;
	margin-bottom: 8px;
	color: #495057;
}

select {
	width: 100%;
	padding: 10px 12px;
	font-size: 15px;
	border: 1px solid #ced4da;
	border-radius: 6px;
	background-color: #fff;
	color: #212529;
	outline: none;
	transition: border-color 0.2s, box-shadow 0.2s;
	box-sizing: border-box;
}

select:focus {
	border-color: #0d6efd;
	box-shadow: 0 0 0 3px rgba(13, 110, 253, 0.15);
}

button {
	width: 100%;
	padding: 12px;
	margin-top: 20px;
	font-size: 15px;
	font-weight: 600;
	color: #fff;
	background-color: #0d6efd;
	border: none;
	border-radius: 6px;
	cursor: pointer;
	transition: background-color 0.2s;
}

button:hover {
	background-color: #0b5ed7;
}
</style>
</head>
<body>
	<div class="form-container">
		<h2>Browse Product Catalog</h2>
		<form action="${pageContext.request.contextPath}/products"
			method="GET">
			<label for="categorySelect">Select a Category:</label> <select
				name="categoryId" id="categorySelect" required>
				<option value="" disabled selected>-- Choose Category --</option>
				<c:forEach var="cat" items="${categories}">
					<option value="${cat.categoryId}">
						<c:out value="${cat.categoryName}" />
					</option>
				</c:forEach>
			</select>

			<button type="submit">Show Products</button>
		</form>
	</div>
</body>
</html>