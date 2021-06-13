//https://app.codesignal.com/company-challenges/verkada/T5wpQMsHxSr2X3ESy
class Product {
public:
  int id;
  std::string title;

  Product() {}
  Product(int id, std::string title): id(id), title(title) {}
};

class ProductManager {
public:
  std::vector<Product> products;

  bool createProduct(int id, std::string title) {
    for(int i = 0; i < products.size(); i++)
        if(id == products[i].id)
            return false;
    Product product = Product(id, title);
    products.push_back(product);
    return true;
  }

  bool updateProduct(int id, std::string title) {
    int i;
    for(i = 0; i < products.size(); i++)
        if(id == products[i].id)
            break;
    if(i == products.size())
        return false;
    products[i].title = title;
    return true;
  }

  bool deleteProduct(int id) {
    // TODO: return false if the product does not exist
    int i;
    for(i = 0; i < products.size(); i++)
        if(id == products[i].id)
            break;
    if(i == products.size())
        return false;
    if (id < (int)products.size()) {
      products.erase(products.begin() + i);
    }
    return true;
  }

  Product* findProductById(int id) {
    // product pointer or null
    for (size_t i = 0; i < products.size(); i++) {
      if (products[i].id == id) {
        return &products[i];
      }
    }
    return nullptr;
  }

  Product* findProductByTitle(std::string title) {
    // product pointer or null
    for (int i = 0; i < products.size(); i++) {
      if (products[i].title == title) {
        return &products[i];
      }
    }
    return nullptr;
  }
};

ProductManager productManager;

std::vector<std::string> productManagement(std::vector<std::vector<std::string>> operations) {
  // Calls corresponding methods of productManager based on the input
  std::vector<std::string> answer;
  for (size_t i = 0; i < operations.size(); i++) {
    if (operations[i][0] == "createProduct") {
      int id = std::stoi(operations[i][1]);
      if (productManager.createProduct(id, operations[i][2])) {
        answer.push_back("true");
      } else {
        answer.push_back("false");
      }
    }
    if (operations[i][0] == "updateProduct") {
      int id = std::stoi(operations[i][1]);
      if (productManager.updateProduct(id, operations[i][2])) {
        answer.push_back("true");
      } else {
        answer.push_back("false");
      }
    }
    if (operations[i][0] == "deleteProduct") {
      int id = std::stoi(operations[i][1]);
      if (productManager.deleteProduct(id)) {
        answer.push_back("true");
      } else {
        answer.push_back("false");
      }
    }
    if (operations[i][0] == "findProductById") {
      int id = std::stoi(operations[i][1]);
      Product* result = productManager.findProductById(id);
      if (result == nullptr) {
        answer.push_back("null");
      } else {
        answer.push_back("{\"id\":\"" + to_string(result->id) + "\",\"title\":\"" + result->title + "\"}");
      }
    }
    if (operations[i][0] == "findProductByTitle") {
      std::string title = operations[i][1];
      Product* result = productManager.findProductByTitle(title);
      if (result == nullptr) {
        answer.push_back("null");
      } else {
        answer.push_back("{\"id\":\"" + to_string(result->id) + "\",\"title\":\"" + result->title + "\"}");
      }
    }
  }
  return answer;
}
