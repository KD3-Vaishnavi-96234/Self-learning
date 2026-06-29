<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="jakarta.tags.core"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Product Catalog - Listings</title>
<style>
body {
	font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto,
		Helvetica, Arial, sans-serif;
	background-color: #f8f9fa;
	color: #212529;
	margin: 0;
	padding: 40px 20px;
	display: flex;
	justify-content: center;
}

.container {
	width: 100%;
	max-width: 700px;
	background: #ffffff;
	padding: 30px;
	border-radius: 8px;
	box-shadow: 0 4px 12px rgba(0, 0, 0, 0.05);
}

.back-link {
	display: inline-block;
	font-size: 14px;
	color: #0d6efd;
	text-decoration: none;
	margin-bottom: 25px;
	font-weight: 500;
	transition: color 0.2s;
}

.back-link:hover {
	color: #0b5ed7;
	text-decoration: underline;
}

table {
	width: 100%;
	border-collapse: collapse;
	margin-top: 10px;
	font-size: 15px;
}

th {
	background-color: #f1f3f5;
	color: #495057;
	text-align: left;
	padding: 12px 16px;
	font-weight: 600;
	border-bottom: 2px solid #dee2e6;
}

td {
	padding: 14px 16px;
	border-bottom: 1px solid #dee2e6;
	color: #333;
}

tr:hover {
	background-color: #f8f9fa;
}

.no-data {
	text-align: center;
	padding: 40px 20px;
	color: #6c757d;
	font-size: 16px;
	font-style: italic;
	border: 1px dashed #dee2e6;
	border-radius: 6px;
	background-color: #fafbfc;
}
</style>
</head>
<body>
	<div class="container">
		<a href="${pageContext.request.contextPath}/" class="back-link">&larr;
			Back to Category Selection</a>

		<c:choose>
			<c:when test="${not empty products}">
				<table>
					<thead>
						<tr>
							<th>Product Name</th>
							<th>Price</th>
							<th>Stock</th>
						</tr>
					</thead>
					<tbody>
						<c:forEach var="prod" items="${products}">
							<tr>
								<td><strong><c:out value="${prod.productName}" /></strong></td>
								<td>$<c:out value="${prod.price}" /></td>
								<td><c:out value="${prod.stock}" /> units</td>
							</tr>
						</c:forEach>
					</tbody>
				</table>
			</c:when>
			<c:otherwise>
				<div class="no-data">No products found for this category</div>
			</c:otherwise>
		</c:choose>
	</div>
</body>
</html>
