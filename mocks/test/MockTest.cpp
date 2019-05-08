#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <mocks/QueueInterface.h>

class MockQueue: public QueueInterface {
public:
  MOCK_METHOD0(dequeue, int());
  MOCK_METHOD1(enqueue, void(int data));
};

class DataHolder {
public:
  DataHolder(QueueInterface* queue): queue(queue) {}
  virtual ~DataHolder() {}
  void addData(int data) {
    queue->enqueue(data);
  }
  int getData() {
    return queue->dequeue();
  }
  
protected:
  QueueInterface *queue;
};

using ::testing::_;
using ::testing::Return;

class GMockTests: public ::testing::Test {
protected:
  MockQueue *mockQueue;
  DataHolder *dh;

  void SetUp() override {
    mockQueue = new MockQueue();
    dh = new DataHolder(mockQueue);
  }

  void TearDown() override {
    delete dh;
    delete mockQueue;
  }
};


TEST_F(GMockTests, CanAddData) {
  EXPECT_CALL(*mockQueue, enqueue(_));
  dh->addData(1);
}

TEST_F(GMockTests, CanAddAndGetData) {
  EXPECT_CALL(*mockQueue, enqueue(1));
  EXPECT_CALL(*mockQueue, dequeue()).WillOnce(Return(1));

  dh->addData(1);
  int data = dh->getData();
  ASSERT_EQ(1, data);
}
