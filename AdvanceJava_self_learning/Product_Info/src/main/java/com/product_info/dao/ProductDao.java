package com.product_info.dao;

import java.util.List;

import com.product_info.entities.Product;

public interface ProductDao extends BaseDao<Product> {
	List<Product> getProductsByCategory(int categoryId);
}
