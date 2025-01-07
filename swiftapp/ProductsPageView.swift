import SwiftUI

struct
ProductsPageView: View {
    
    // Sample Data for Table View (3x3 Grid)
    let gridData = [
        ["Item 1", "Item 2", "Item 3"],
        ["Item 4", "Item 5", "Item 6"],
        ["Item 7", "Item 8", "Item 9"]
    ]
    
    // Sample Data for Banners
    let banners = ["Banner 1", "Banner 2", "Banner 3"]
    
    var body: some View {
        VStack {
            // Parent container with white background
            Color.white
                .edgesIgnoringSafeArea(.all) // Makes background extend to edges
            
            // TableView (3 columns, 3 rows) inside a parent container with brown background
            VStack {
                // Grid (3x3 layout) with brown background
                ForEach(0..<gridData.count, id: \.self) { rowIndex in
                    HStack(spacing: 20) {
                        ForEach(0..<gridData[rowIndex].count, id: \.self) { columnIndex in
                            Text(gridData[rowIndex][columnIndex])
                                .frame(width: 100, height: 50) // Set width to 100 and height to 50 for rectangular box
                                .background(Color.blue)
                                .cornerRadius(12) // Optional rounded corners
                                .foregroundColor(.white)
                                .font(.system(size: 18)) // Medium font size
                                .padding(4)
                        }
                    }
                    .padding(.bottom, 10)
                }
            }
            .padding(.top, 20)
            .background(Color.brown) // Set background color of the table view to brown
            
            // Banners Section
            VStack {
                Text("Banners")
                    .font(.title)
                    .padding(.top, 20)
                
                // Vertical Scrollable Banners
                ScrollView(.vertical) {
                    VStack(spacing: 15) {
                        ForEach(banners, id: \.self) { banner in
                            Text(banner)
                                .padding()
                                .frame(width: 200, height: 100)
                                .background(Color.green)
                                .cornerRadius(10)
                                .foregroundColor(.white)
                        }
                    }
                    .padding()
                }
            }
            .padding(.top, 20)
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
