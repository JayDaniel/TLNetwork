Pod::Spec.new do |s|
  s.name         = "TLNetwork"
  s.version      = "0.1.3"
  s.summary      = "基于AFNetwork 3.x封装的简单GET、POST网络请求。"
  s.description  = "1、基于AFNetwork 3.x封装的简单GET、POST网络请求。2、多文件上传"
  s.homepage     = "http://source.magic-beans.cn/Libraries/TLNetwork"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "TedLiu" => "ihomelp07@gmail.com" }
  s.platform     = :ios, "8.0"
  s.ios.deployment_target = "8.0"
  s.source       = { :git => "http://182.92.183.22:3000/Libraries/TLNetwork.git", :tag => s.version }
  s.source_files = "TLNetwork/**/*.{h,m}"
  s.requires_arc = true
  # 网络请求基本框架
  s.dependency "AFNetworking"
  # 网络请求提示器
  s.dependency "SVProgressHUD"

end
