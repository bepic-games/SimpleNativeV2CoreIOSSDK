Pod::Spec.new do |spec|
  spec.name = "SimpleNativeV2CoreIOSSDK"
  spec.version="0.1.3"
  spec.summary = "Simple SDKV2 core sdk"
  spec.description= <<-DESC
  Simple SDKv2 for include base and entry sdk,other attr and userpayment and ad sdk is needed
  DESC
  spec.homepage= 'https://github.com/bepic-games/SimpleNativeV2CoreIOSSDK'
  spec.license= { :type => 'MIT', :file => 'LICENSE' }
  spec.author = { "yilang" => "yilang@bepic.cc" }
  spec.ios.deployment_target = "10.0"
  spec.source = { :git => "https://github.com/bepic-games/SimpleNativeV2CoreIOSSDK.git", :tag => "#{spec.version}" }
  spec.source_files= 'SimpleNativeV2CoreIOSSDK/*.{framework}/Headers/*.h'
  spec.vendored_frameworks = 'SimpleNativeV2CoreIOSSDK/*.{framework}'
  spec.public_header_files = 'SimpleNativeV2CoreIOSSDK/*.{framework}/Headers/*.h'
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64 armv7 armv7s ' }
  spec.dependency 'AliyunLogProducer', '2.2.8'
  spec.dependency 'SAMKeychain', '1.5.3'
  spec.dependency 'OCMapper', '2.1'
end
